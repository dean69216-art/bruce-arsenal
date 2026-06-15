#include "OthersMenu.h"

#include "core/display.h"
#include "core/utils.h"
#include "modules/badusb_ble/ducky_typer.h"
#include "modules/bjs_interpreter/interpreter.h"
#include "modules/others/clicker.h"
#include "modules/others/ibutton.h"
#include "modules/others/mic.h"
#include "modules/others/qrcode_menu.h"
#include "modules/others/tururururu.h"
#include "modules/others/u2f.h"
#include "modules/arsenal/arsenal.h"
#include "modules/arsenal/arsenal_config.h"
#include "modules/arsenal/arsenal_background.h"
// Removed: #include "modules/others/timer.h"

void OthersMenu::optionsMenu() {
    options = {
        {"QRCodes",      qrcode_menu                  },
        {"Megalodon",    shark_setup                  },

#if defined(MIC_SPM1423) || defined(MIC_INMP441)
        {"Microphone",   [this]() { micMenu(); }      }, //@deveclipse
#endif

// New consolidated BadUSB & HID submenu
#if !defined(LITE_VERSION)
#if defined(USB_as_HID)
        {"BadUSB & HID", [this]() { badUsbHidMenu(); }},
#endif
#endif

#ifndef LITE_VERSION
        {"iButton",      setup_ibutton                },
#endif

        {"Arsenal",      [this]() { arsenalMenu(); }  },

        // Timer removed - moved to another "Clock"
    };

    addOptionToMainMenu();
    loopOptions(options, MENU_TYPE_SUBMENU, "Others");
}

void OthersMenu::badUsbHidMenu() {
    options = {
#ifndef LITE_VERSION
        {"BadUSB",       [=]() { ducky_setup(hid_usb, false); }   },
        {"USB Keyboard", [=]() { ducky_keyboard(hid_usb, false); }},
#endif

#ifdef USB_as_HID
        {"USB Clicker",  clicker_setup                            },
        {"USB U2F",      u2f_setup                                },
#endif

        {"Back",         [this]() { optionsMenu(); }              },
    };

    loopOptions(options, MENU_TYPE_SUBMENU, "BadUSB & HID");
}

void OthersMenu::micMenu() {
    options = {
#if defined(MIC_SPM1423) || defined(MIC_INMP441)
        {"Spectrum", mic_test                   },
        {"Record",   mic_record_app             },
#endif
        {"Back",     [this]() { optionsMenu(); }},
    };

    loopOptions(options, MENU_TYPE_SUBMENU, "Microphone");
}

void OthersMenu::drawIcon(float scale) {
    clearIconArea();

    // Dynamic radius calculation based on scale for responsive rendering
    int radius = scale * 7;

    // Center circle
    tft.fillCircle(iconCenterX, iconCenterY, radius, bruceConfig.priColor);

    // Concentric arcs - dynamically scaled for different screen sizes
    tft.drawArc(
        iconCenterX, iconCenterY, 2.5 * radius, 2 * radius, 0, 340, bruceConfig.priColor, bruceConfig.bgColor
    );

    tft.drawArc(
        iconCenterX, iconCenterY, 3.5 * radius, 3 * radius, 20, 360, bruceConfig.priColor, bruceConfig.bgColor
    );

    tft.drawArc(
        iconCenterX, iconCenterY, 4.5 * radius, 4 * radius, 0, 200, bruceConfig.priColor, bruceConfig.bgColor
    );

    tft.drawArc(
        iconCenterX,
        iconCenterY,
        4.5 * radius,
        4 * radius,
        240,
        360,
        bruceConfig.priColor,
        bruceConfig.bgColor
    );
}

void OthersMenu::arsenalMenu() {
    if (!arsenal_pin_check()) {
        displayRedStripe("Access denied");
        delay(1500);
        return;
    }

    // Auto-start background OPSEC monitoring on first Arsenal visit
    if (!arsenal_background_is_running()) {
        arsenal_background_start();
    }

    options = {
        {"Intelligence",   [this]() { arsenalIntelligenceMenu(); } },
        {"Evasion",        [this]() { arsenalEvasionMenu(); }      },
        {"Phishing",       [this]() { arsenalPhishingMenu(); }     },
        {"Detection",      [this]() { arsenalDetectionMenu(); }    },
        {"Comms",          [this]() { arsenalCommsMenu(); }        },
        {"Utility",        [this]() { arsenalUtilityMenu(); }      },
        {"Combos",         arsenal_combo_menu               },
        {"Scheduler",      arsenal_attack_scheduler         },
        {"Scripts",        arsenal_script_browser           },
        {"Session Log",    arsenal_session_log_menu         },
        {"Jam All",        arsenal_jam_all                  },
#if !LITE_VERSION
        {"Dashboard",      arsenal_remote_dashboard         },
#endif
        {"Config AP",      arsenal_config_ap                },
        {"Config Dash",    arsenal_config_dashboard         },
        {"PIN Lock",       arsenal_pin_lock                 },
        {"Back",           [this]() { optionsMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Arsenal");
}

void OthersMenu::arsenalIntelligenceMenu() {
    options = {
        {"OPSEC Monitor",      arsenal_opsec_monitor            },
        {"OUI Lookup",         arsenal_oui_lookup               },
        {"Probe Log",          arsenal_wifi_probe_log           },
        {"Banner Grabber",     arsenal_service_banner_grabber   },
#if !LITE_VERSION
        {"SmartHome Scan",     arsenal_smart_home_scanner       },
#endif
        {"Channel Chart",      arsenal_wifi_channel_chart       },
#if !LITE_VERSION
        {"People Counter",     arsenal_people_counter           },
#endif
        {"Device Nickname",    arsenal_device_nickname          },
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Intelligence");
}

void OthersMenu::arsenalEvasionMenu() {
    options = {
        {"MAC Rotator",        arsenal_mac_rotator              },
        {"Channel Hopper",     arsenal_channel_hopper           },
        {"Decoy Traffic",      arsenal_decoy_traffic            },
        {"Identity Cloner",    arsenal_identity_cloner          },
        {"Time Randomizer",    arsenal_time_based_randomizer    },
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Evasion");
}

void OthersMenu::arsenalPhishingMenu() {
    options = {
        {"Win Update",         arsenal_phish_windows_update     },
        {"WiFi Speed",         arsenal_phish_wifi_speed         },
        {"OAuth Phish",        arsenal_phish_oauth              },
        {"Device Found",       arsenal_phish_device_found       },
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Phishing Portals");
}

void OthersMenu::arsenalDetectionMenu() {
    options = {
#if !LITE_VERSION
        {"Flipper Detector",   arsenal_flipper_detector         },
        {"Hacker Detector",    arsenal_hacker_detector          },
        {"RF Silence",         arsenal_rf_silence_enforcer      },
#endif
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Detection");
}

void OthersMenu::arsenalCommsMenu() {
    options = {
#if !LITE_VERSION
        {"ESP-NOW Chat",       arsenal_espnow_chat              },
        {"ESP-NOW C2",         arsenal_espnow_c2                },
#endif
#if !LITE_VERSION
        {"Dead Drop Mesh",     arsenal_dead_drop_mesh           },
        {"IR Data Transfer",   arsenal_ir_data_transfer         },
        {"Multi-Device Sync",  arsenal_multi_device_sync        },
#endif
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Comms");
}

void OthersMenu::arsenalUtilityMenu() {
    options = {
#if !LITE_VERSION
        {"NFC Biz Card",       arsenal_nfc_business_card        },
#endif
        {"Attack Stats",       arsenal_attack_stats             },
        {"Password Gen",       arsenal_password_generator       },
        {"QR Poisoner",        arsenal_qr_poisoner              },
        {"Back",               [this]() { arsenalMenu(); }      },
    };
    loopOptions(options, MENU_TYPE_SUBMENU, "Utility");
}
