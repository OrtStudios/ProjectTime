#include "Walnut/Application.h"
#include "Walnut/EntryPoint.h"
#include "Walnut/Image.h"

#include "Oort/Icons.h"
#include "Oort/Settings.h"

class Menu : public Walnut::Layer
{
public:
	virtual void OnAttach() override
	{
		ProjectTimeLogoImage = std::make_shared<Walnut::Image>("Assets/Images/MenuLogo.png");
		
	}

	virtual void OnUIRender() override
	{
		// Start the Dear ImGui frame
		ImGui::Begin("ProjectTimeMenuWindow");
		
		
		// Create a side bar
		ImGui::BeginChild("SideBar", ImVec2(90, 0), true);
		ImGui::Image(ProjectTimeLogoImage->GetDescriptorSet(), {80, 80});
		ImGui::EndChild();

		// End the Dear ImGui frame
		ImGui::End();
	}

private:
	std::shared_ptr<Walnut::Image> ProjectTimeLogoImage;
};


Walnut::Application* Walnut::CreateApplication(int argc, char** argv)
{
	// Create the Walnut Application Specs
	Walnut::ApplicationSpecification ProjectTimeAppSpecs;
	ProjectTimeAppSpecs.Name = "ProjectTime";

	// Create The Walnut Application
	Walnut::Application* ProjectTimeApp = new Walnut::Application(ProjectTimeAppSpecs);
	
	ProjectTimeApp->PushLayer<Menu>();
	return ProjectTimeApp;
}