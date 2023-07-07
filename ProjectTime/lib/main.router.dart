import 'package:go_router/go_router.dart';

// Pages
import 'package:project_time/pages/404.dart';
import 'package:project_time/pages/homePage.dart';
import 'package:project_time/pages/ProjectsLibrary.dart';
import 'package:project_time/pages/projects/addProject.dart';

// Util
import 'package:project_time/utils/routerTransition.dart';

final ptRouter = GoRouter(
        routes: [
            GoRoute(
                path: '/',
                name: "home",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const HomePage()
                )
            ),
            GoRoute(
                path: '/projectsLibrary',
                name: "projectsLibrary",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ProjectsLibraryPage()
                )
            ),
            GoRoute(
                path: '/projects/addProject',
                name: "addProject",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const AddProjectPage()
                )
            ),
            GoRoute(
                path: '/projects/:projectID',
                name: "project",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/calender',
                name: "calender",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/account',
                name: "account",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/settings',
                name: "settings",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/about',
                name: "about",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            ),
            GoRoute(
                path: '/404',
                name: "404",
                pageBuilder: (context, state) => ptRouterPageBuilder(
                    context, state, const ErrorPage()
                )
            )
        ],
    );