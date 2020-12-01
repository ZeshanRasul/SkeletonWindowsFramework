#include "Input.h"

///////////////////////
///KEYBOARD FUNCTIONS//
///////////////////////

bool Input::IsKeyPressed(unsigned char keycode)
{
	return keystates[keycode];
}

std::optional<Input::InputKeyboardEvent> Input::ReadKey()
{
	if (keybuffer.size() > 0)
	{
		InputKeyboardEvent event = keybuffer.front();
		keybuffer.pop();
		return event;
	}
	return {};
}

bool Input::IsKeyEmpty()
{
	return keybuffer.empty();
}

void Input::FlushKey()
{
	keybuffer = std::queue<InputKeyboardEvent>();
}

std::optional<char> Input::ReadChar()
{
	if (charbuffer.size() > 0)
	{
		unsigned char charcode = charbuffer.front();
		charbuffer.pop();
		return charcode;
	}
	return {};
}

bool Input::IsCharEmpty()
{
	return charbuffer.empty();
}

void Input::FlushChar()
{
	charbuffer = std::queue<char>();
}

void Input::EnableAutorepeat()
{
	autorepeatEnabled = true;
}

void Input::DisableAutorepeat()
{
	autorepeatEnabled = false;
}

bool Input::IsAutorepeatEnabled()
{
	return autorepeatEnabled;
}

void Input::OnKeyPressed(unsigned char keycode)
{
	keystates[keycode] = true;
	keybuffer.push(InputKeyboardEvent(InputKeyboardEvent::Type::Press, keycode));
	TrimKeyboardBuffer(keybuffer);
}

void Input::OnKeyReleased(unsigned char keycode)
{
	keystates[keycode] = false;
	keybuffer.push(InputKeyboardEvent(InputKeyboardEvent::Type::Release, keycode));
	TrimKeyboardBuffer(keybuffer);
}

void Input::OnChar(char character)
{
	charbuffer.push(character);
	TrimKeyboardBuffer(charbuffer);
}

void Input::ClearState()
{
	keystates.reset();
}

template<typename T>
void Input::TrimKeyboardBuffer(std::queue<T>& buffer)
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}
