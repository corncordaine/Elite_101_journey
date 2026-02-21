# Trading Logic Library — C

A collection of C programs implementing trading concepts from first principles like ICT , indicators and derivatives from mathematical concepts.

## Files

- `price_set_manager.c` — Set theory in action: checks if price belongs to support/resistance zones with tolerance-based membership testing.
- `choch_detector.c` — Detects Change of Character (CHoCH) by finding previous swing highs and checking close prices.
- `multi_tier_filter.c` — Multi-condition trade filter with input validation.

##  Concepts Covered

- Universal quantifiers (`∀`) → `for` loops
- Set theory → arrays and membership checks
- Logical operators → trade conditions
- Time windows → `within_3h()` function structure

##  How to Run

```bash
gcc price_set_manager.c -o manager -lm
./manager