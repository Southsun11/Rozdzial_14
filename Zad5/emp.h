#pragma once
#include <string>
#include <iostream>
class abstr_emp
{
private:
	std::string m_fname;
	std::string m_lname;
	std::string m_job;
public:
	abstr_emp():m_fname("brak"), m_lname("brak"), m_job("brak") {}
	abstr_emp(const std::string& fname, const std::string& lname, const std::string& job) :m_fname(fname), m_lname(lname), m_job(job) {}
	virtual void showAll() const;
	virtual void setAll();
	friend std::ostream& operator<<(std::ostream& os, const abstr_emp& e);
	virtual ~abstr_emp() = 0;

};

class employee :public abstr_emp
{
public:
	employee() :abstr_emp() {}
	employee(const std::string& fname, const std::string& lname, const std::string job) :abstr_emp(fname, lname, job) {}
	virtual void showAll()const;
	virtual void setAll();
};

class Manager :virtual public abstr_emp
{
private:
	int m_inchargeof;
protected:
	int inChargeof()const { return m_inchargeof; };
	int& inChargeof() { return m_inchargeof; }
public:
	Manager() :abstr_emp(), m_inchargeof(0) {}
	Manager(const std::string fname, const std::string lname, const std::string job, int inchargeof)
		:abstr_emp(fname, lname, job), m_inchargeof(inchargeof) {}
	Manager(const abstr_emp& e, int inchargeof) :abstr_emp(e), m_inchargeof(inchargeof) {}
	Manager(const Manager& m) :abstr_emp(m), m_inchargeof(m.m_inchargeof) {}
	virtual void showAll() const;
	virtual void setAll();
};

class Fink :virtual public abstr_emp
{
private:
	std::string m_reportsTo;
protected:
	const std::string reportsTo() const { return m_reportsTo; }
	std::string& reportsTo() { return m_reportsTo; }
public:
	Fink() :abstr_emp(), m_reportsTo("brak") {}
	Fink(const std::string& fname, const std::string& lname, const std::string& job, const std::string reportsTo)
		:abstr_emp(fname, lname, job), m_reportsTo(reportsTo) {}
	Fink(const abstr_emp& e, const std::string reportsTo) :abstr_emp(e), m_reportsTo(reportsTo) {}
	Fink(const Fink & f) :abstr_emp(f), m_reportsTo(f.m_reportsTo) {}
	virtual void showAll() const;
	virtual void setAll();

};

class HighFink : public Manager, public Fink
{
public:
	HighFink();
	HighFink(const std::string& fname, const std::string& lname, const std::string& job, const std::string& reportTo, int inchargeof);
	HighFink(const abstr_emp& e, const std::string& reportsTo, int inchargeof);
	HighFink(const Fink& f, int inchargeof);
	HighFink(const Manager& m, const std::string& reportTo);
	HighFink(const HighFink& hf) :abstr_emp(hf), Manager(hf), Fink(hf) {}
	virtual void showAll() const;
	virtual void setAll();


};