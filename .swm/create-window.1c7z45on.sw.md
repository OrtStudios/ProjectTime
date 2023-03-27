---
id: 1c7z45on
title: Create Window
file_version: 1.1.2
app_version: 1.4.7
---

inure the initializing of the wigets of flutter.<br/>
then we insure the initializing of the window with the "window manager" package.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 ProjectTime/lib/main.dart
```dart
22         WidgetsFlutterBinding.ensureInitialized();
23         windowManager.ensureInitialized();
```

<br/>

we wait until the window has initialized and then we run the app with the Flutter "runApp" function.
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 ProjectTime/lib/main.dart
```dart
25         await Window.initialize();
26     
27         runApp(const ProjectTime());
```

<br/>

TODO
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 ProjectTime/lib/main.dart
```dart
29         windowManager.waitUntilReadyToShow().then(
30             (_) async 
31             {
32             // await windowManager.setTitleBarStyle(TitleBarStyle.hidden);
33                 await windowManager.setAsFrameless();
34                 await windowManager.setHasShadow(false);
35                 windowManager.show();
36             }
37         );
```

<br/>

setting the window properties:

*   size -> see in_ `config.dart`
    
*   title -> "Project Time"
    
*   minSize and maxSize are the same and to be seen in `config.dart`
    
*   alignment -> center
    
    at the end we show the window
<!-- NOTE-swimm-snippet: the lines below link your snippet to Swimm -->
### 📄 ProjectTime/lib/main.dart
```dart
39         doWhenWindowReady(() 
40             {
41                 appWindow
42                     ..size = ptConfig.winSize
43                     ..title = "Project Time"
44                     ..minSize = ptConfig.winSize
45                     ..maxSize = ptConfig.winSize
46                     ..alignment = Alignment.center
47                     ..show();
48             }
49         );
```

<br/>

<br/>

<br/>

This file was generated by Swimm. [Click here to view it in the app](/repos/Z2l0aHViJTNBJTNBUHJvamVjdFRpbWUlM0ElM0FPcnRTdHVkaW9z/docs/1c7z45on).