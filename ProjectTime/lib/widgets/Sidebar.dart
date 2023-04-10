// ignore_for_file: file_names, library_prefixes, non_constant_identifier_names, constant_identifier_names, must_be_immutable

import 'package:flutter/material.dart';
import 'package:go_router/go_router.dart';
//import 'package:project_time/extensions/VRouter.dart';

// Utils
import 'package:project_time/utils/pageIndex.dart';
import 'package:project_time/utils/roundOutwards.dart';

// Data
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

class Sidebar extends StatelessWidget 
{
    final List<NavigationRailDestination> SidebarDestinations = const [
        NavigationRailDestination(
            icon: Icon(Icons.house_outlined),
            selectedIcon: Icon(Icons.house),
            label: Text('Home'),
        ),
        NavigationRailDestination(
            icon: Icon(Icons.library_books_outlined),
            selectedIcon: Icon(Icons.library_books),
            label: Text('Projects Library'),
        ),
        NavigationRailDestination(
            icon: Icon(Icons.settings_outlined),
            selectedIcon: Icon(Icons.settings),
            label: Text('Settings'),
        ),
    ];

    final Widget page;
    Sidebar({super.key, required this.page});

    int setIndex()
    {
        int index = GetPageIndex(page);

        // check if the index of the page is in the sidebar:
        if (ptConfig.PagesInSidebar.contains(index))
        {
            return index;
        }
        else
        {
            return 0;
        }
    }

    BuildContext? context;

    @override
    Widget build(BuildContext context) 
    {
        this.context = context;
        return Container(
            height: ptConfig.windowHeight,
            width: ptConfig.sidebarWidth,
            color: ptTheme.kPrimaryColor,
            child: ClipPath(
                clipper: OutwardsClipper(),
                child: NavigationRail(
                    destinations: const [
                        NavigationRailDestination(
                            icon: Icon(Icons.house_outlined),
                            selectedIcon: Icon(Icons.house),
                            label: Text('Home'),
                        ),
                        NavigationRailDestination(
                            icon: Icon(Icons.library_books_outlined),
                            selectedIcon: Icon(Icons.library_books),
                            label: Text('Projects Library')
                        ),
                        NavigationRailDestination(
                            icon: Icon(Icons.settings_outlined),
                            selectedIcon: Icon(Icons.settings),
                            label: Text('Settings'),
                        ),
                    ],
                    selectedIndex: setIndex(),
                    onDestinationSelected: changeDestination,
                    useIndicator: true,
                ),
            )
        );
    }

    void changeDestination(int value) 
    {
        if (this.context == null) return;

        BuildContext context = this.context!;

        switch (value) 
        {
            case 0:
                context.go("/");
                break;
            case 1:
                context.go("/projectsLibrary");
                break;
            case 2:
                context.go("/settings");
                break;
        }
    }
}