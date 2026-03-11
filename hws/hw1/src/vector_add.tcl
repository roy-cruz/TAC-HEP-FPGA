open_project proj_vector_add
set_top vector_add
add_files vector_add.cpp
#add_files vector_add.h
#add_files -tb vector_add_out_ref.dat
add_files -tb vector_add_tb.cpp

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
