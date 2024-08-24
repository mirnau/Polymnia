#pragma once
#include <queue>
#include <cstdint>
#include <bitset>

using std::queue;
using std::bitset;

class Keyboard
{
	friend class Window;

public:
	class Event
	{
	public:
		enum class Type
		{
			Pressed,
			Released,
			Invalid,
		};
	private:
		Type type;
		unsigned char code;

	public:
		Event() noexcept;
		Event(Type type, unsigned char code) noexcept;
		Event(const Event&) = default;
		Event(Event&&) = default;
		~Event() = default;
		Event& operator=(const Event&) = default;

	public:
		bool IsPressed() const noexcept;
		bool IsReleased() const noexcept;
		bool IsInvalid() const noexcept;
	};

public:
	Keyboard() = default;
	Keyboard(const Keyboard&) = default;
	Keyboard(Keyboard&&) = delete;
	~Keyboard() = default;
	Keyboard& operator=(const Keyboard&) = default;

public:
	bool KeyIsPressed(unsigned char keycode) const noexcept;
	bool IsAutoRepeatEnabled() const noexcept;
	char ReadChar() noexcept;
	Event ReadKey() noexcept;
	void ClearChar() noexcept;
	void ClearKey() noexcept;
	void Clear() noexcept;
	void EnableAutoRepeat() noexcept;
	void DisableAutoRepeat() noexcept;

private:
	void OnKeyPressed(unsigned char keycode) noexcept;
	void OnKeyReleased(unsigned char keycode) noexcept;
	void OnChar(char character) noexcept;

public:
	void ClearState() noexcept;

private:
	template<typename T>
	static void TrimBuffer(queue<T>& buffer) noexcept;

private:
	static constexpr uint16_t nKeys = 256u;
	static constexpr uint8_t bufferSize = 16u;
	bool autoRepeatEnabled = false;
	bitset<nKeys> keyStates;
	queue<Event> keyBuffer;
	queue<char> charBuffer;
};

template<typename T>
inline void Keyboard::TrimBuffer(queue<T>& buffer) noexcept
{
	while (buffer.size() > bufferSize)
	{
		buffer.pop();
	}
}
