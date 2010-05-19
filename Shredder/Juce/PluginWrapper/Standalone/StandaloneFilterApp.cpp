#ifdef JucePlugin_Build_Standalone

#include "Includes.h"
#include "../Juce/PluginWrapper/Standalone/juce_StandaloneFilterWindow.h"

class ShredderApp : public JUCEApplication
{
	public:
		ShredderApp()
		{
		}

		void initialise(const String& commandLineParameters)
		{
			ApplicationProperties::getInstance()->setStorageParameters(T("Shredder"), String::empty, T("Shredder"), 400, PropertiesFile::storeAsXML);
			
			filterWindow = new StandaloneFilterWindow (T("Shredder"), Colours::black);
			filterWindow->setTitleBarButtonsRequired (DocumentWindow::allButtons, false);
			filterWindow->setVisible (true);
			filterWindow->setResizable (true, true);
			filterWindow->setName (T("Shredder"));
		}

		void shutdown()
		{
			deleteAndZero (filterWindow);
		}

		const String getApplicationName()
		{
			return T("Shredder");
		}
		
		const String getApplicationVersion()
		{
			return T("4.0");
		}

	private:
		StandaloneFilterWindow *filterWindow;
};

START_JUCE_APPLICATION (ShredderApp)

#endif