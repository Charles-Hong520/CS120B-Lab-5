test "PINA: 1,0 2 times -> PORTB: 0x00, 0x01, 0x01, 0x05"
setPINA 0xFF
continue 2
expectPORTB 0x00
setPINA 0xFE
continue 2
expectPORTB 0x01
setPINA 0xFF
continue 2
expectPORTB 0x01
setPINA 0xFE
continue 2
expectPORTB 0x05
checkResult