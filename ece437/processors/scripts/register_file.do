onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /system_tb/DUT/CPU/DP/rf/CLK
add wave -noupdate /system_tb/DUT/CPU/DP/rf/nRST
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/ihit
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/halt
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/jr
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/zero
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/b_eq
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/b_ne
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/imm
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/jmp
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/jaddr
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/lr
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/pc
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/final_npc
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/pc_plus4
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/pc_plus4_plusimm
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/b
add wave -noupdate -expand -group pc /system_tb/DUT/CPU/DP/pc1/shifted_jaddr
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/zero
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/overflow
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/negative
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/aluop
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/port_a
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/port_b
add wave -noupdate -group alu /system_tb/DUT/CPU/DP/alu1/aluif/output_port
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/ihit
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/dhit
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/halt
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/imemload
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/iREN
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/dREN
add wave -noupdate -group {Request Unit} /system_tb/DUT/CPU/DP/ru/dWEN
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/imemload
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/jmp
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/jmpr
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/j_al
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/b_eq
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/b_ne
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/rf_write
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/alu_src
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/reg_dst
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/alu_op
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/memtoreg
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/hlt
add wave -noupdate -group {Control Unit} /system_tb/DUT/CPU/DP/controller/l_ui
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/halt
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/ihit
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/imemREN
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/imemload
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/imemaddr
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dhit
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/datomic
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dmemREN
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dmemWEN
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/flushed
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dmemload
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dmemstore
add wave -noupdate -group dpif /system_tb/DUT/CPU/DP/dpif/dmemaddr
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/iwait
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/dwait
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/iREN
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/dREN
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/dWEN
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/iload
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/dload
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/dstore
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/iaddr
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/daddr
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramWEN
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramREN
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramstate
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramaddr
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramstore
add wave -noupdate -expand -group {Memory Control} /system_tb/DUT/CPU/ccif/ramload
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/iwait
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/dwait
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/iREN
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/dREN
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/dWEN
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/iload
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/dload
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/dstore
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/iaddr
add wave -noupdate -expand -group Cache /system_tb/DUT/CPU/CM/cif/daddr
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/CLK
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/nRST
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/count
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/rstate
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/q
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/addr
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/wren
add wave -noupdate -expand -group RAM /system_tb/DUT/RAM/en
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rf/regs
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/WEN
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/wsel
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/rsel1
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/rsel2
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/wdat
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/rdat1
add wave -noupdate -expand -group {Register File} /system_tb/DUT/CPU/DP/rfif/rdat2
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {13767 ps} 0}
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
WaveRestoreZoom {0 ps} {245120 ps}
