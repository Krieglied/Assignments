# Lab 8c: Shadow Sequence Number

```c
unsigned long shadow_sequence_number(int placeNumber);
```

* Purpose
    * Define shadow_sequence_number() as a recursive function that returns a "shadow sequence" number of position "placeNumber"
    * Do not calculate a sequence number greater than 2300
* Parameters - Shadow Sequence number position to calculate
* Return Value
    * placeNumber on success
    * 105 if placeNumber is unrealistic or dangerous
* The Shadow Sequence:
    * Starts with 9 and 0 then each subsequent number is calculated by adding the previous value and the square of the position
    * S(n) = S(n-1) + (n*n)