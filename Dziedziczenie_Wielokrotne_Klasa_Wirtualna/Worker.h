#pragma once
#include <string>
class Worker
{
private:
	std::string m_fullname;
	int m_id;
protected:
	virtual void get();
	virtual void data() const;
public:
	Worker() :m_fullname("Brak"), m_id(0) {};
	Worker(const std::string& s, int i) : m_fullname("Brak"), m_id(i) {}
	virtual ~Worker() = 0;
	virtual void show() const = 0;
	virtual void set() = 0;
};


class Waiter : virtual public  Worker
{
private:
	int m_panache;
protected:
	void virtual data() const;
	void virtual get();
public:
	Waiter() :Worker(), m_panache(0) {}
	Waiter(const std::string& s, int i, int n = 0) : Worker(s, i), m_panache(n) {}
	Waiter(const Worker& w, int n = 0) :Worker(w), m_panache(n) {}
	virtual ~Waiter() {};
	virtual void show() const;
	virtual void set() ;
};

class Singer :virtual public  Worker
{
protected:
	enum { inny, Vtypes = 7 };
	virtual void data() const;
	virtual void get();
private:
	static const char* m_pv[Vtypes];
	int m_voice;
public:
	Singer() :Worker(), m_voice(inny) {}
	Singer(const std::string& s, int i, int v) :Worker(s, i), m_voice(v) {}
	Singer(const Worker& w, int v) :Worker(w), m_voice(v) {}
	virtual ~Singer() {};
	virtual void set();
	virtual void show() const;
};

class SingingWaiter :public Waiter, public Singer
{
protected:
	virtual void data() const;
	virtual void get();
public:
	SingingWaiter() {}
	SingingWaiter(const std::string& s, int i, int n = 0 , int v = inny) :Worker(s, i), Waiter(s, i, n), Singer(s, i, v) {}
	SingingWaiter(const Worker& w, int n = 0, int v = inny) :Worker(w), Waiter(w, n), Singer(w, v) {}
	SingingWaiter(const Waiter& w, int v = inny) :Worker(w), Waiter(w), Singer(w, v) {}
	SingingWaiter(const Singer& s, int n = 0) :Worker(s), Waiter(s, n), Singer(s) {}
	~SingingWaiter() {};
	virtual void set();
	virtual void show() const;

	
};



