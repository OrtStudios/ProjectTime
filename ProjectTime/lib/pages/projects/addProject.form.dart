// ignore_for_file: library_prefixes, curly_braces_in_flow_control_structures

import 'package:flutter/material.dart';
import 'package:project_time/pages/projects/addProject.form.extras.dart';

// Widgets
import 'package:project_time/widgets/Forms/Buttons.dart';
import 'package:project_time/pages/projects/addProject.form.general.dart';

// Other
import 'package:project_time/Core.logger.dart';
import 'package:project_time/extensions/VRouter.dart';

class AddProjectForm extends StatefulWidget 
{
    const AddProjectForm({super.key});

    @override
    State<AddProjectForm> createState() => _AddProjectFormState();
}

class _AddProjectFormState extends State<AddProjectForm> 
{
    int currentStep = 0;

    List<Step> getSteps() => [
        Step(
            state: currentStep > 0 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 0,
            title: const Text("General"),
            content: const AddProjectFormGeneralPage()
        ),
        Step(
            state: currentStep > 1 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 1,
            title: const Text("Type"),
            content: Container()
        ),
        Step(
            state: currentStep > 2 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 2,
            title: const Text("Location"),
            content: Container()
        ),
        Step(
            state: currentStep > 3 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 3,
            title: const Text("Autor"),
            content: Container()
        ),
        Step(
            state: currentStep > 4 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 4,
            title: const Text("Extras"),
            content: const AddProjectFormExtrasPage()
        ),
        Step(
            state: currentStep > 5 ? StepState.complete : StepState.indexed,
            isActive: currentStep >= 5,
            title: const Text("Confermation"),
            content: Container()
        )
    ];

    @override
    Widget build(BuildContext context) 
    {
        return Stepper(
            type: StepperType.horizontal,
            elevation: 0,
            steps: getSteps(),
            currentStep: currentStep,
            onStepContinue: () => setState(
                () {
                    final isLastStep = currentStep == getSteps().length - 1;

                    if (isLastStep) 
                    {
                        Core.logInfo("continue");
                        widget.goto(context, "/projectsLibrary");
                    } 
                    else currentStep++;
                }
            ),
            onStepTapped: (step) => setState(() => currentStep = step),
            onStepCancel: currentStep == 0
                ? null
                : () => setState(() => currentStep--),
            controlsBuilder: (context, details) {
                return Container(
                    margin: const EdgeInsets.only(top: 50),
                    child: Row(
                        children: [
                            FormButton("Back", onPressed: details.onStepCancel),
                            const SizedBox(width: 12),
                            FormButton("Continue", onPressed: details.onStepContinue),
                        ]
                    )
                );
            }
        );
    }
}
