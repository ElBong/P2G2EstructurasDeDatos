#pragma once
#include "Libraries.h"
class RuntimeException {
private:
	string message;
public:
	RuntimeException(const string& message) {
		this->message = message;
	}
	string ErrorMessage() const { return this->message; }
};

class InvalidOption : public RuntimeException {
public:
	InvalidOption(const string& error) : RuntimeException(error) {}
};

class ClientNotFound : public RuntimeException {
	public:
	ClientNotFound(const string& error) : RuntimeException(error) {}
};

class EmptyHeapPriorityQueue : public RuntimeException {
public:
	EmptyHeapPriorityQueue(const string& error) : RuntimeException(error) {}
};

class DataTransferred : public RuntimeException {
public:
	DataTransferred(const string& error) : RuntimeException(error) {}
};

class FileError : public RuntimeException {
public:	
	FileError(const string& error) : RuntimeException(error) {}
};

class invalidData : public RuntimeException {
public:
	invalidData(const string& error) : RuntimeException(error) {}
};

class IndexOverflow : public RuntimeException {
public:
	IndexOverflow(const string& error) : RuntimeException(error) {}
};

class DuplicatedClient : public RuntimeException {
public:
	DuplicatedClient(const string& error) : RuntimeException(error) {}
};

class EmptyVector : public RuntimeException {
public:
	EmptyVector(const string& error) : RuntimeException(error) {}
};
