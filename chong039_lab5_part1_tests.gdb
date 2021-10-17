echo ======================================================\n
echo Running all tests..."\n\n

test "PINA: 127 => PORTC: 0x40"
setPINA 127
continue 2
expectPORTC 0x40
checkResult

test "PINA: 126 => PORTC: 0x60"
setPINA 126
continue 2
expectPORTC 0x60
checkResult

test "PINA: 125 => PORTC: 0x60"
setPINA 125
continue 2
expectPORTC 0x60
checkResult

test "PINA: 124 => PORTC: 0x70"
setPINA 124
continue 2
expectPORTC 0x70
checkResult

test "PINA: 123 => PORTC: 0x70"
setPINA 123
continue 2
expectPORTC 0x70
checkResult

test "PINA: 122 => PORTC: 0x38"
setPINA 122
continue 2
expectPORTC 0x38
checkResult

set $passed=$tests-$failed
eval "shell echo Passed %d/%d tests.\n",$passed,$tests
echo ======================================================\n
