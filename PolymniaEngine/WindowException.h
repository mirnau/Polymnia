#pragma once

#include <cstdint>
#include "BaseEngineException.h"
#include "Window.h"

using std::string;

class WindowException : public BaseEngineException
{
public:
	WindowException(uint32_t line, const char* file, HRESULT hr) noexcept;
	~WindowException() = default;

public:
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	static string TranslateErrorCode(HRESULT hr);
	HRESULT GetErrorCode() const noexcept;
	string GetErrorString() const noexcept;
	
private:
	HRESULT hr;
};