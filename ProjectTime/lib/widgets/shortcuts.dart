import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:go_router/go_router.dart';

// Other
import 'package:new_keyboard_shortcuts/keyboard_shortcuts.dart';
import 'package:project_time/extensions/VRouter.dart';

class ShortCuts extends StatefulWidget 
{
    final Widget child;
    const ShortCuts({required this.child, Key? key}) : super(key: key);

    @override
    State<ShortCuts> createState() => _ShortCutsState();
}

class _ShortCutsState extends State<ShortCuts> 
{
    @override
    Widget build(BuildContext context) 
    {
        return KeyBoardShortcuts(
            globalShortcuts: true,
            keysToPress: {LogicalKeyboardKey.controlLeft, LogicalKeyboardKey.keyH},
            onKeysPressed: () => widget.goto(context, "/"),
            child: KeyBoardShortcuts(
                globalShortcuts: true,
                keysToPress: {LogicalKeyboardKey.keyF}, //! PLACEHOLDER SHORTCUT
                onKeysPressed: () => context.go("/account"),
                child: widget.child
            )
        );
    }
}