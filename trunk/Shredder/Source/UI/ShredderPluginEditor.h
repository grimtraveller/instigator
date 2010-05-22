#ifndef __SHREDDER_PLUGIN_EDITOR_26D6D62E__
#define __SHREDDER_PLUGIN_EDITOR_26D6D62E__

#include "Includes.h"
#include "ShredderPlugin.h"
class ShredderSlot;
class ShredderMidiSlot;

class ShredderPluginEditor : public DocumentWindow
{
	public:
		ShredderPluginEditor(ShredderPlugin *_shredderPlugin, ShredderSlot *_shredderSlot);
		ShredderPluginEditor(ShredderPlugin *_shredderPlugin, ShredderMidiSlot *_shredderSlot);
		~ShredderPluginEditor();
		void closeButtonPressed();
		void resized();
		void moved();

	private:
		int x,y;
		ShredderPlugin *shredderPlugin;
		ShredderSlot *shredderSlot;
		ShredderMidiSlot *shredderMidiSlot;
};

#endif