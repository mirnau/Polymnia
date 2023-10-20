#pragma once

#include <algorithm>
#include "Keyboard.hpp"

//KEYBOARD::EVENT CLASS

Keyboard::Event::Event() noexcept
	:
	type(Type::Invalid),
	code(0u)
{}

Keyboard::Event::Event(Type type, unsigned char code) noexcept
	:
	type(type),
	code(code)
{}

bool Keyboard::Event::IsPressed() const noexcept
{
	return type == Type::Pressed;
}

bool Keyboard::Event::IsReleased() const noexcept
{
	return type == Type::Released;
}

bool Keyboard::Event::IsInvalid() const noexcept
{
	return type == Type::Invalid;
}

//KEYBOARD CLASS

bool Keyboard::KeyIsPressed(unsigned char keycode) const noexcept
{
	return keyStates[keycode];
}

bool Keyboard::IsAutoRepeatEnabled() const noexcept
{
	return autoRepeatEnabled;
}

char Keyboard::ReadChar() noexcept
{
	if (charBuffer.size() > 0u)
	{
		auto code = charBuffer.front();

		if (!charBuffer.empty())
		{
			charBuffer.pop();
		}

		return code;
	}

	return 0;
}

Keyboard::Event Keyboard::ReadKey() noexcept
{
	if (keyBuffer.size() > 0u)
	{
		Keyboard::Event event = keyBuffer.front();
		if (!keyBuffer.empty())
		{
			keyBuffer.pop();
		}
		return event;
	}

	return Keyboard::Event();
}

void Keyboard::ClearChar() noexcept
{
	charBuffer = queue<char>{};

}

void Keyboard::ClearKey() noexcept
{
	keyBuffer = queue<Event>{};
}

void Keyboard::Clear() noexcept
{
	ClearChar();
	ClearKey();
}

void Keyboard::EnableAutoRepeat() noexcept
{
	autoRepeatEnabled = true;
}

void Keyboard::DisableAutoRepeat() noexcept
{
	autoRepeatEnabled = false;
}

void Keyboard::OnKeyPressed(unsigned char keycode) noexcept
{
	keyStates[keycode] = true;
	keyBuffer.push(Keyboard::Event(Keyboard::Event::Type::Pressed, keycode));
	TrimBuffer(keyBuffer);
}

void Keyboard::OnKeyReleased(unsigned char keycode) noexcept
{
	keyStates[keycode] = false;
	keyBuffer.push(Keyboard::Event(Keyboard::Event::Type::Released, keycode));
	TrimBuffer(keyBuffer);
}


void Keyboard::OnChar(char character) noexcept
{
	charBuffer.push(character);
	TrimBuffer(charBuffer);
}

void Keyboard::ClearState() noexcept
{
	keyStates.reset();
}