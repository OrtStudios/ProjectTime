// ignore_for_file: file_names

import 'package:flutter/material.dart';

// Theme Colors
const Color kPrimaryColor = Color(0xFF0D2D5A);
const Color kPrimaryTransparentColor = Color(0x7F0D2D5A);
const Color kSecondaryColor = Color(0xFF0094B1);
const Color kSecondaryLightColor = Color(0xFF6BE6FF);
const Color kSecondaryTransparentColor = Color(0x480093B1);
const Color kAccentColor = Color(0xFFD8A120);
const Color kAccentTransparentColor = Color(0x7FD8A120);
const Color kBackgroundColor = Color(0x00000000);
const Color kTextColor = Color(0xFFFFFFFF);
const Color kDisabledTextColor = Color(0xFF8D8D8D);
const Color kTextTransparentColor = Color(0x7FFFFFFF);
const Color kButtonBackgroundColor = Color(0x8F0093B1);
const Color kDisabledButtonBackgroundColor = Color(0x8F002D36);
const Color kSidebarBackgroundColor = Color(0xFF0D2D5A);

// Theme Images
const String kLogoImage = "assets/images/logo.png";
const String kBackgroundImage = "assets/images/background.png";

// Theme Text Styles
ThemeData mainTheme = ThemeData(
    useMaterial3: true,
    primaryColor: kPrimaryColor,
    colorScheme: const ColorScheme.dark(
        primary: kPrimaryColor,
        secondary: kAccentColor,
        onPrimary: kTextColor,
        onSecondary: kTextColor,
        background: kBackgroundColor
    ),
);