onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /control_unit_tb/DUT/CLK
add wave -noupdate /control_unit_tb/DUT/nRST
add wave -noupdate /control_unit_tb/DUT/imemload
add wave -noupdate /control_unit_tb/DUT/jmp
add wave -noupdate /control_unit_tb/DUT/jmpr
add wave -noupdate /control_unit_tb/DUT/j_al
add wave -noupdate /control_unit_tb/DUT/b_eq
add wave -noupdate /control_unit_tb/DUT/b_ne
add wave -noupdate /control_unit_tb/DUT/rf_write
add wave -noupdate /control_unit_tb/DUT/alu_src
add wave -noupdate /control_unit_tb/DUT/reg_dst
add wave -noupdate /control_unit_tb/DUT/alu_op
add wave -noupdate /control_unit_tb/DUT/memtoreg
add wave -noupdate /control_unit_tb/DUT/hlt
add wave -noupdate /control_unit_tb/DUT/l_ui
add wave -noupdate /control_unit_tb/PROG/testcase
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {241 ns} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 100
configure wave -justifyvalue left
configure wave -signalnamewidth 1
configure wave -snapdistance 10
configure wave -datasetprefix 0
configure wave -rowmargin 4
configure wave -childrowmargin 2
configure wave -gridoffset 0
configure wave -gridperiod 1
configure wave -griddelta 40
configure wave -timeline 0
configure wave -timelineunits ns
update
WaveRestoreZoom {0 ns} {1 us}
