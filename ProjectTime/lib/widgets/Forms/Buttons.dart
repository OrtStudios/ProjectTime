// ignore_for_file: file_names, curly_braces_in_flow_control_structures, library_prefixes

import 'package:flutter/material.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;

class FormButton extends StatelessWidget 
{
    const FormButton(this.text, {required this.onPressed, super.key});

    final VoidCallback? onPressed;
    final String text;

    @override
    Widget build(BuildContext context) 
    {
        return Expanded(
            child: ElevatedButton(
                onPressed: onPressed,
                style: ButtonStyle(
                    backgroundColor: MaterialStateProperty.resolveWith<Color>(
                        (Set<MaterialState> states) 
                        {
                            if (states.contains(MaterialState.disabled))
                                return ptTheme.kDisabledButtonBackgroundColor;
                            return ptTheme.kButtonBackgroundColor;
                        }
                    ),
                    foregroundColor: MaterialStateProperty.resolveWith<Color>(
                        (Set<MaterialState> states) 
                        {
                            if (states.contains(MaterialState.disabled))
                                return ptTheme.kDisabledTextColor;
                            return ptTheme.kTextColor;
                        }
                    ),

                ),
                child: Text(text)
            )
        );
    }
}