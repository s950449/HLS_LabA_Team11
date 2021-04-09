############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project dasd
set_top top
add_files duplicate_io_ctrl/duplicate_io_ctrl.cpp
add_files duplicate_io_ctrl/duplicate_io_ctrl.h
add_files -tb duplicate_io_ctrl/duplicate_io_ctrl_tb.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
#source "./dasd/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
