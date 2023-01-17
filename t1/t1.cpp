// t1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#define __NS_TOOLS_DEBUG_CONSOL__ 1

#include <iostream>
#include <vector>

#include <ct_dev.h>
#include <ct_dev_primitive.h>
#include <ct_dev_composite.h>
#include <ct_dev_hid.h>
#include <ct_dev_lpu200.h>


int main()
{
    std::wcout << L"Hello World!\n";
    //
    std::vector<_ns_tools::ct_dev::type_ptr> v_ptr;

    v_ptr.push_back(_ns_tools::ct_dev::type_ptr(new _ns_tools::ct_dev(_ns_tools::ct_tool_dev::type_bm_dev_hid, L"test_path")));
    v_ptr.push_back(_ns_tools::ct_dev::type_ptr(new _ns_tools::ct_dev_primitive()));
    v_ptr.push_back(_ns_tools::ct_dev::type_ptr(new _ns_tools::ct_dev_hid()));
    //v_ptr.push_back(_ns_tools::ct_dev::type_ptr(new _ns_tools::ct_dev_lpu200(v_ptr[2], _ns_tools::ct_tool_dev::type_bm_dev_lpu200_msr, L"test_msr")));

    v_ptr[0]->is_open();
    v_ptr[1]->is_open();
    v_ptr[2]->is_open();

}
