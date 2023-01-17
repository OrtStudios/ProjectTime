// ignore_for_file: file_names

import 'package:flutter/material.dart';

// Theme Colors
const Color kPrimaryColor = Color(0xFF0D2D5A);
const Color kSecondaryColor = Color(0xFF0094B1);
const Color kAccentColor = Color(0xFFD8A120);
const Color kBackgroundColor = Color(0xFF000000);
const Color kTextColor = Color(0xFFFFFFFF);

// Theme Images
const String kLogoImage = "assets/images/logo.png";
const String kBackgroundImage = "assets/images/background.png";

// Theme Text Styles
ThemeData mainTheme = ThemeData(
    primaryColor: kPrimaryColor,
    colorScheme: const ColorScheme.dark(
        primary: kPrimaryColor,
        secondary: kSecondaryColor,
        onPrimary: kTextColor,
        onSecondary: kTextColor,
    ),
    backgroundColor: kBackgroundColor,
    textTheme: const TextTheme(
        headline1: TextStyle(
            fontSize: 30,
            color: kTextColor,
        ),
        headline2: TextStyle(
            fontSize: 25,
            color: kTextColor,
        ),
        headline3: TextStyle(
            fontSize: 20,
            color: kTextColor,
        ),
        headline4: TextStyle(
            fontSize: 15,
            color: kTextColor,
        ),
        headline5: TextStyle(
            fontSize: 10,
            color: kTextColor,
        ),
        bodyText1: TextStyle(
            fontSize: 20,
            color: kTextColor,
        ),
        bodyText2: TextStyle(
            fontSize: 15,
            color: kTextColor,
        )
    )
);