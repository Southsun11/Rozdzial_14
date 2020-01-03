#pragma once
#include <string>
class Worker
{
private:
	std::string m_fullname;
	int m_id;
public:
	Worker() :m_fullname("brak"), m_id(0) {}
	Worker(const std::string& s, long n) :m_fullname(s), m_id(n) {}
	virtual ~Worker() {}
	virtual void set();
	virtual void show() const;
};

class Waiter :public Worker
{
private:
	int m_pancache;
public:
	Waiter() :Worker(), m_pancache(0) {}
	Waiter(const std::string& s, long n, int p = 0) :Worker(s, n), m_pancache(p) {}
	Waiter(const Worker& w, int p = 0) :Worker(w), m_pancache(p) {}
	void set();
	void show() const;
};

class Singer : public Worker
{
protected:
		enum { inny, Vtypes = 7 };
private:
	static const char* pv[Vtypes];
	int m_voice;
public:
	Singer() :Worker(), m_voice(inny) {}
	Singer(const std::string& s, long n, int v = inny) :Worker(s, n), m_voice(v) {}
	Singer(const Worker& w, int v = inny) :Worker(w), m_voice(v) {}
	void set();
	void show() const;
};

