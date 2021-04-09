############################################################
## This file is generated automatically by Vivado HLS.
## Please DO NOT edit it.
## Copyright (C) 1986-2019 Xilinx, Inc. All Rights Reserved.
############################################################
open_project DirectInput
set_top top
add_files ../src/directinput_ctrl/directinput_ctrl.cpp
add_files ../src/directinput_ctrl/directinput_ctrl.h
add_files -tb ../src/directinput_ctrl/directinput_ctrl_tb.cpp
open_solution "solution1"
set_part {xc7z020clg484-1}
create_clock -period 5 -name default
config_sdx -target none
config_export -vivado_optimization_level 2 -vivado_phys_opt place -vivado_report_level 0
#source "./DirectInput/solution1/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
