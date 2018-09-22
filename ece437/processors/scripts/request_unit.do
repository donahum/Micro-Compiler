onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /request_unit_tb/DUT/CLK
add wave -noupdate /request_unit_tb/DUT/nRST
add wave -noupdate /request_unit_tb/DUT/ihit
add wave -noupdate /request_unit_tb/DUT/dhit
add wave -noupdate /request_unit_tb/DUT/halt
add wave -noupdate /request_unit_tb/DUT/imemload
add wave -noupdate /request_unit_tb/DUT/iREN
add wave -noupdate /request_unit_tb/DUT/dREN
add wave -noupdate /request_unit_tb/DUT/dWEN
add wave -noupdate /request_unit_tb/PROG/testcase
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {44 ns} 0}
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
WaveRestoreZoom {0 ns} {126 ns}
