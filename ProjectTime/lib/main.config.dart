// ignore_for_file: constant_identifier_names

import 'package:flutter/material.dart';

const double windowWidth = 1000;
const double windowHeight = 600;
const double sidebarWidth = 150;

const Size winSize = Size(windowWidth, windowHeight);

const Map<String, int> PagesCategories = {
    "404": -1,
    "Home": 0,
    "Project": 1,
    "settings": 2,
};

const PagesByCategories = {
    "Home": "Home",
    "404": "Home",
    "ProjectsLibrary": "Project",
    "AddProject": "Project",
};

const PagesInSidebar = [
    0, 1, 2
];