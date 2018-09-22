onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /memory_control_tb/CLK
add wave -noupdate /memory_control_tb/nRST
add wave -noupdate /memory_control_tb/PROG/testcase
add wave -noupdate /memory_control_tb/tb_cif0/iwait
add wave -noupdate /memory_control_tb/tb_cif0/dwait
add wave -noupdate /memory_control_tb/tb_cif0/iREN
add wave -noupdate /memory_control_tb/tb_cif0/dREN
add wave -noupdate /memory_control_tb/tb_cif0/dWEN
add wave -noupdate /memory_control_tb/tb_cif0/iload
add wave -noupdate /memory_control_tb/tb_cif0/dload
add wave -noupdate /memory_control_tb/tb_cif0/dstore
add wave -noupdate /memory_control_tb/tb_cif0/iaddr
add wave -noupdate /memory_control_tb/tb_cif0/daddr
add wave -noupdate /memory_control_tb/tb_cif0/ccwait
add wave -noupdate /memory_control_tb/tb_cif0/ccinv
add wave -noupdate /memory_control_tb/tb_cif0/ccwrite
add wave -noupdate /memory_control_tb/tb_cif0/cctrans
add wave -noupdate /memory_control_tb/tb_cif0/ccsnoopaddr
add wave -noupdate /memory_control_tb/tb_rif/ramREN
add wave -noupdate /memory_control_tb/tb_rif/ramWEN
add wave -noupdate /memory_control_tb/tb_rif/ramaddr
add wave -noupdate /memory_control_tb/tb_rif/ramstore
add wave -noupdate /memory_control_tb/tb_rif/ramload
add wave -noupdate /memory_control_tb/tb_rif/ramstate
add wave -noupdate /memory_control_tb/tb_rif/memREN
add wave -noupdate /memory_control_tb/tb_rif/memWEN
add wave -noupdate /memory_control_tb/tb_rif/memaddr
add wave -noupdate /memory_control_tb/tb_rif/memstore
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {0 ps} 0}
quietly wave cursor active 0
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
WaveRestoreZoom {655544050 ps} {655545050 ps}
