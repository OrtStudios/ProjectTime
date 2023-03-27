// ignore_for_file: file_names, library_prefixes, curly_braces_in_flow_control_structures
import "package:flutter/material.dart";
import 'package:project_time/Core.dart';
import 'package:project_time/extensions/VRouter.dart';

// Widgets
import 'package:project_time/widgets/base.dart';
import 'package:project_time/widgets/Forms/Buttons.dart';

// Other
import 'package:project_time/main.theme.dart' as ptTheme;
import 'package:project_time/main.config.dart' as ptConfig;

class AddProjectPage extends StatefulWidget
{
    const AddProjectPage({super.key});

    @override
    State<AddProjectPage> createState() => _AddProjectPageState();
}

class _AddProjectPageState extends State<AddProjectPage> 
{
    int currentStep = 0;

    List<Step> getSteps() => [
        Step(
            state: currentStep > 0 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 0,
            title: const Text("General"),
            content: Column(
                mainAxisAlignment: MainAxisAlignment.start,
                textDirection: TextDirection.ltr,
                children: [
                    Row(
                        children: [
                            const Text("Name: "),
                            TextFormField()
                        ]
                    )
                ]
            )
        ),
        Step(
            state: currentStep > 1 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 1,
            title: const Text("Type"),
            content: Container()
        ),
        Step(
            state: currentStep > 2 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 2,
            title: const Text("Location"),
            content: Container()
        ),
        Step(
            state: currentStep > 3 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 3,
            title: const Text("Autor"),
            content: Container()
        ),
        Step(
            state: currentStep > 4 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 4,
            title: const Text("Extras"),
            content: Container()
        ),
        Step(
            state: currentStep > 5 
                ? StepState.complete
                : StepState.indexed,
            isActive: currentStep >= 5,
            title: const Text("Confermation"),
            content: Container()
        )
    ];

    @override
    Widget build(BuildContext context) 
    {
        return Material(
            child: BaseWidget(
                child: Row(
                    children: [
                        Container(
                            height: ptConfig.windowHeight,
                            color: ptTheme.kPrimaryColor,
                            child: const Text(
                                "Unimplemented", // TODO: Implement SideBar
                                style: TextStyle(
                                    color: ptTheme.kSecondaryColor,
                                    fontWeight: FontWeight.normal,
                                    decoration: TextDecoration.none,
                                    fontSize: 15
                                )
                            )
                        ),
                        SizedBox(
                            width: ptConfig.windowWidth - 245,
                            height: ptConfig.windowHeight - 12,
                            child: Theme(
                                data: ptTheme.mainTheme,
                                child: Stepper(
                                    type: StepperType.horizontal,
                                    steps: getSteps(),
                                    currentStep: currentStep,
                                    onStepContinue: () => setState(() {
                                        final isLastStep = currentStep == getSteps().length - 1;
                            
                                        if (isLastStep)
                                        {
                                            Core.logInfo("continue");
                                            widget.goto(context, "/projectsLibrary");
                                        }
                                        else
                                            currentStep++;
                                    }),
                                    onStepTapped: (step) => setState(() => currentStep = step),
                                    onStepCancel: currentStep == 0 
                                        ? null
                                        : () => setState(() => currentStep--),
                                    controlsBuilder: (context, details) {
                                        return Container(
                                            margin: const EdgeInsets.only(top: 50),
                                            child: Row(
                                                children: [
                                                    FormButton(
                                                        "Back", 
                                                        onPressed: details.onStepCancel
                                                    ),
                                                    const SizedBox(width: 12),
                                                    FormButton(
                                                        "Continue", 
                                                        onPressed: details.onStepContinue
                                                    ),
                                                ]
                                            )
                                        );
                                    }
                                )
                            )
                        )
                    ]
                )
            )
        );
    }
}