# Move Encoding

moves are encoded in a compact 32-bit format with fields for from, to, flags,
and promotion. this layout keeps hot path decoding cheap and cache friendly.

## references

- <https://example.com>
