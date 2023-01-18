// t1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define __NS_TOOLS_DEBUG_CONSOL__ 1

#include <iostream>
#include <vector>

#include <ct_type.h>

class i_root 
{
public:
    typedef std::shared_ptr<i_root>  type_ptr;

public:
    virtual int add(int, int) = 0;
    virtual int sub(int, int) = 0;

    virtual ~i_root()
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
    }
};

class croot : public i_root
{
public:
    typedef std::shared_ptr<croot>  type_ptr;

public:
    virtual int add(int a, int b)
    {
        m_n_last_add =  a + b;
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return m_n_last_add;
    }
    virtual int sub(int a, int b)
    {
        m_n_last_sub =  a - b;
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return m_n_last_sub;
    }

    int mul(int a, int b)
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return a * b;
    }
public:
    croot() : m_n_last_add(0), m_n_last_sub(0)
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
    }

    virtual ~croot()
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
    }
protected:
    int m_n_last_add;

private:
    int m_n_last_sub;

};

class csub : public croot
{
public:
    typedef std::shared_ptr<csub>  type_ptr;

public:
    virtual int add(int a, int b)
    {
        m_n_last_add = a + b;
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return m_n_last_add;
    }
    virtual int sub(int a, int b)
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return a-b;
    }

    int mul(int a, int b)
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
        return a * b;
    }

public:
    csub() 
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
    }
    csub( int a,int b)
    {
        wprintf_s(L"[%s](int, int) exit.\n", __WFUNCTION__);
    }

    ~csub()
    {
        wprintf_s(L"[%s]() exit.\n", __WFUNCTION__);
    }
protected:
private:

};



int main()
{
    std::wcout << L"Hello World!\n";
    //
    i_root::type_ptr ptr_root(new croot());

    ptr_root->add(1, 2);
    ptr_root->sub(2, 3);
    //ptr_root->mul(3, 4);

    ptr_root.reset();
    //
    i_root::type_ptr ptr_sub(new csub(3,4));
    ptr_sub->add(1, 2);
    ptr_sub->sub(2, 3);
    //ptr_sub->mul(3, 4);

    ptr_sub.reset();
    //
    csub::type_ptr ptr_sub1(new csub(3, 4));
    ptr_sub1->add(1, 2);
    ptr_sub1->sub(2, 3);
    ptr_sub1->mul(3, 4);

    ptr_sub1.reset();



    std::wcout << L"good bye!\n";
}
