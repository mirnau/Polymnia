#include <sstream>
#include "WindowException.h"

using std::endl;

WindowException::WindowException(uint32_t line, const char* file, HRESULT hr) noexcept
	:
	BaseEngineException(line, file),
	hr(hr)
{}

const char* WindowException::what() const noexcept
{
	ostringstream oss;
	oss << GetType() << endl
		<< "[Error Code]" << GetErrorCode() << endl
		<< "[Description]" << GetErrorString() << endl
		<< GetOriginString();
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* WindowException::GetType() const noexcept
{
	return "Window Exception";
}

string WindowException::TranslateErrorCode(HRESULT hr)
{
	char* pMsgBuff{ nullptr };
	DWORD nMsgLen = FormatMessage(
		FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_IGNORE_INSERTS,
		nullptr,
		hr,
		MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT),
		reinterpret_cast<LPWSTR>(&pMsgBuff),
		0,
		nullptr
	);

	if (nMsgLen == 0)
	{
		return "Unidentified Error Code";
	}

	string errorString{ pMsgBuff };
	LocalFree(pMsgBuff);

	return errorString;
}

HRESULT WindowException::GetErrorCode() const noexcept
{
	return hr;
}

string WindowException::GetErrorString() const noexcept
{
	return string();
}
