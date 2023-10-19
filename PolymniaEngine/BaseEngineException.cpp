#include <sstream>
#include "BaseEngineException.h"

using std::endl;

BaseEngineException::BaseEngineException(uint32_t line, const char* file) noexcept
	:
	line(line),
	file(file)
{}

const char* BaseEngineException::what() const noexcept
{
	ostringstream oss;
	oss << "[File]" << file << endl
		<< "[Line]" << line << endl;
	whatBuffer = oss.str();
	return whatBuffer.c_str();
}

const char* BaseEngineException::GetType() const noexcept
{
	return nullptr;
}

uint32_t BaseEngineException::GetLine() const noexcept
{
	return line;
}

const string& BaseEngineException::GetFile() const noexcept
{
	return file;
}

string BaseEngineException::GetOriginString() const noexcept
{
	ostringstream oss;
	oss << "[File]" << file << endl
		<< "[Line]" << line << endl;
	return oss.str();
}
