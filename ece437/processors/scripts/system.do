onerror {resume}
quietly WaveActivateNextPane {} 0
add wave -noupdate /system_tb/DUT/CLK
add wave -noupdate /system_tb/DUT/nRST
add wave -noupdate -radix hexadecimal -childformat {{{/system_tb/DUT/CPU/DP/ifidif/pc[31]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[30]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[29]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[28]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[27]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[26]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[25]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[24]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[23]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[22]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[21]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[20]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[19]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[18]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[17]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[16]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[15]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[14]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[13]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[12]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[11]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[10]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[9]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[8]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[7]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[6]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[5]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[4]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[3]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[2]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[1]} -radix hexadecimal} {{/system_tb/DUT/CPU/DP/ifidif/pc[0]} -radix hexadecimal}} -subitemconfig {{/system_tb/DUT/CPU/DP/ifidif/pc[31]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[30]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[29]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[28]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[27]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[26]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[25]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[24]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[23]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[22]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[21]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[20]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[19]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[18]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[17]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[16]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[15]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[14]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[13]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[12]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[11]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[10]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[9]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[8]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[7]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[6]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[5]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[4]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[3]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[2]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[1]} {-height 17 -radix hexadecimal} {/system_tb/DUT/CPU/DP/ifidif/pc[0]} {-height 17 -radix hexadecimal}} /system_tb/DUT/CPU/DP/ifidif/pc
add wave -noupdate /system_tb/DUT/CPU/DP/npc
add wave -noupdate /system_tb/DUT/CPU/DP/exmemif/jmprMEM
add wave -noupdate /system_tb/DUT/CPU/DP/b
add wave -noupdate /system_tb/DUT/CPU/DP/exmemif/jmpMEM
add wave -noupdate /system_tb/DUT/CPU/DP/exmemif/dRENMEM
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/instr
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/pc
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/pcIF
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/instrIF
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/rsIF
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/rtIF
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/rdIF
add wave -noupdate -group ifid /system_tb/DUT/CPU/DP/ifidLatch/ifidif/immIF
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/jmpDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/b_neDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/b_eqDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/alu_srcDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/haltDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/dRENDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/dWENDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/l_uiDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/extend_signDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/jmprDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rf_writeDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/reg_dstDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/j_alDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/pcDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/instrDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/immDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rdat1DEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rdat2DEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/opEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/opDEC
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rdat1EX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rdat2EX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/jmpEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/b_neEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/b_eqEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/alu_srcEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/haltEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/dRENEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/dWENEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/l_uiEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/extend_signEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/jmprEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/rf_writeEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/reg_dstEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/j_alEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/pcEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/immEX
add wave -noupdate -group idex /system_tb/DUT/CPU/DP/idexLatch/idexif/instrEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/zeroEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/jmpEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/b_eqEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/b_neEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/haltEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/dRENEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/dWENEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/jmprEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rf_writeEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/reg_dstEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/j_alEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/resultEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/alu_srcEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/pcEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/instrEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/immEX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rdat2EX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rdat1EX
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/jmpMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/b_eqMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/b_neMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/haltMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/dRENMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/dWENMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/jmprMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rf_writeMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/reg_dstMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/j_alMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/resultMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/alu_srcMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/pcMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/instrMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/immMEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rdat2MEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/rdat1MEM
add wave -noupdate -group exmem /system_tb/DUT/CPU/DP/exMemLatch/exmemif/zeroMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/zeroMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/jmpMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/b_eqMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/b_neMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/haltMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/dRENMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/dWENMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/reg_dstMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/j_alMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/resultMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/rf_writeMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/pcMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/instrMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/immMEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/rdat2MEM
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/jmpWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/b_eqWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/b_neWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/haltWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/reg_dstWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/j_alWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/rf_writeWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/dRENWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/dWENWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/pcWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/instrWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/immWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/rdat2WB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/resultWB
add wave -noupdate -group memwb /system_tb/DUT/CPU/DP/memwbLatch/memwbif/zeroWB
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/imemload
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/jmp
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/jmpr
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/j_al
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/b_eq
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/b_ne
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/rf_write
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/alu_src
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/reg_dst
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/extend_sign
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/dREN
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/dWEN
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/alu_op
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/memtoreg
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/hlt
add wave -noupdate -group Controller /system_tb/DUT/CPU/DP/controller/l_ui
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rf/regs
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/WEN
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/wsel
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/rsel1
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/rsel2
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/wdat
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/rdat1
add wave -noupdate -expand -group RF /system_tb/DUT/CPU/DP/rfif/rdat2
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/zero
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/overflow
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/negative
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/aluop
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/port_a
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/port_b
add wave -noupdate -group ALU /system_tb/DUT/CPU/DP/aluif/output_port
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/halt
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/ihit
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/imemREN
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/imemload
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/imemaddr
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dhit
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dmemREN
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dmemWEN
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/flushed
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dmemload
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dmemstore
add wave -noupdate -expand -group dpif /system_tb/DUT/CPU/DP/dpif/dmemaddr
add wave -noupdate /system_tb/DUT/CPU/DP/itype
add wave -noupdate /system_tb/DUT/CPU/DP/jtype
add wave -noupdate /system_tb/DUT/CPU/DP/rtype
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/iwait
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/dwait
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/iREN
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/dREN
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/dWEN
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/iload
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/dload
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/dstore
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/iaddr
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/daddr
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ccwait
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ccinv
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ccwrite
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/cctrans
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ccsnoopaddr
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramWEN
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramREN
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramstate
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramaddr
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramstore
add wave -noupdate -group memory_control /system_tb/DUT/CPU/CC/ccif/ramload
TreeUpdate [SetDefaultTree]
WaveRestoreCursors {{Cursor 1} {375536 ps} 0}
quietly wave cursor active 1
configure wave -namecolwidth 150
configure wave -valuecolwidth 124
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
WaveRestoreZoom {0 ps} {431916 ps}
