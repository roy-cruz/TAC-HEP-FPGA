open_project proj_matrix_mult
set_top matrix_mult
add_files matrix_mult.cpp
#add_files matrix_add.h
#add_files -tb matrix_add_out_ref.dat
add_files -tb matrix_mult_tb.cpp

open_solution "solution1"
set_part {xcvu9p-flga2104-1-i}
create_clock -period 25 -name default

#source "./fir_proj/solution1/directives.tcl"

csim_design
csynth_design
#cosim_design
#export_design -format ip_catalog
#
exit
