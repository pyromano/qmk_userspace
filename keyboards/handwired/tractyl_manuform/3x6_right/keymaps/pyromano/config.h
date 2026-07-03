// Copyright 2024 pyromano
// SPDX-License-Identifier: GPL-3.0-or-later

#pragma once

#define CHARYBDIS_MINIMUM_DEFAULT_DPI     500
#define CHARYBDIS_DEFAULT_DPI_CONFIG_STEP 100
#define CHARYBDIS_MINIMUM_SNIPING_DPI     200
#define CHARYBDIS_SNIPING_DPI_CONFIG_STEP 100

#define PMW33XX_LIFTOFF_DISTANCE 0x0A

// Axis inversion
#define POINTING_DEVICE_INVERT_Y

// Auto-mouse layer (moves to mouse layer when trackball moves)
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define AUTO_MOUSE_TIME 1250

// Auto-sniping on mouse layer
#define CHARYBDIS_AUTO_SNIPING_ENABLE
