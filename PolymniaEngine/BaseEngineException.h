#pragma once

#include <exception>
#include <cstdint>
#include <string>

using std::exception;
using std::string;
using std::ostringstream;


class BaseEngineException : exception
{
public:
	BaseEngineException(uint32_t line, const char* file) noexcept;
	BaseEngineException(BaseEngineException&) = delete;
	~BaseEngineException() = default;

public:
	const char* what() const noexcept override;
	virtual const char* GetType() const noexcept;
	uint32_t GetLine() const noexcept;
	const string& GetFile() const noexcept;
	string GetOriginString() const noexcept;

private:
	uint32_t line;
	string file;

protected:
	mutable string whatBuffer;

};