// ignore_for_file: file_names

import 'package:flutter/material.dart';

// Theme Colors
const Color kPrimaryColor = Color(0xFF0D2D5A);
const Color kPrimaryTransparentColor = Color(0x7F0D2D5A);
const Color kSecondaryColor = Color(0xFF0094B1);
const Color kSecondaryTransparentColor = Color.fromARGB(73, 0, 147, 177);
const Color kAccentColor = Color(0xFFD8A120);
const Color kAccentTransparentColor = Color(0x7FD8A120);
const Color kBackgroundColor = Color(0xFF000000);
const Color kBackgroundTransparentColor = Color(0x7F000000);
const Color kTextColor = Color(0xFFFFFFFF);
const Color kTextTransparentColor = Color(0x7FFFFFFF);

// Theme Images
const String kLogoImage = "assets/images/logo.png";
const String kBackgroundImage = "assets/images/background.png";

// Theme Text Styles
ThemeData mainTheme = ThemeData(
    useMaterial3: true,
    primaryColor: kPrimaryColor,
    colorScheme: const ColorScheme.dark(
        primary: kPrimaryColor,
        secondary: kSecondaryColor,
        onPrimary: kTextColor,
        onSecondary: kTextColor,
        background: kBackgroundColor
    )
);