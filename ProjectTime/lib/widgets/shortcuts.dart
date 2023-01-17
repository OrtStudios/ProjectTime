import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:new_keyboard_shortcuts/keyboard_shortcuts.dart';
import 'package:vrouter/vrouter.dart';

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
            keysToPress: {LogicalKeyboardKey.escape}, //! PLACEHOLDER SHORTCUT
            onKeysPressed: () => context.vRouter.toNamed("home"),
            child: KeyBoardShortcuts(
                globalShortcuts: true,
                keysToPress: {LogicalKeyboardKey.keyF}, //! PLACEHOLDER SHORTCUT
                onKeysPressed: () => context.vRouter.toNamed("account"),
                child: widget.child
            )
        );
    }
}