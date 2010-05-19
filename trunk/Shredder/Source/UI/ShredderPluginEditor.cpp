#include "ShredderPluginEditor.h"
#include "ShredderEditor.h"

ShredderPluginEditor::ShredderPluginEditor(ShredderPlugin *_shredderPlugin, ShredderSlot *_shredderSlot) 
	:	DocumentWindow (String::empty, Colours::aliceblue, DocumentWindow::closeButton, true), 
		shredderPlugin(_shredderPlugin),
		shredderSlot(_shredderSlot)
{
	if (shredderPlugin->getLastPos().isEmpty())
	{
		setContentComponent (shredderPlugin->getEditor(), true, true);
		centreAroundComponent (shredderSlot, getWidth(), getHeight());
	}
	else
	{
		setBounds (shredderPlugin->getLastPos());
		setContentComponent (shredderPlugin->getEditor(), true, false);
	}

	setName (shredderPlugin->getName());
	setVisible (true);
}

ShredderPluginEditor::~ShredderPluginEditor()
{
	shredderPlugin->editorClosed(false);
}

void ShredderPluginEditor::closeButtonPressed()
{
	setVisible (false);
}

void ShredderPluginEditor::resized()
{
	shredderPlugin->setLastPos (getBounds());
	DocumentWindow::resized();
}

void ShredderPluginEditor::moved()
{
	shredderPlugin->setLastPos (getBounds());
	DocumentWindow::moved();
}