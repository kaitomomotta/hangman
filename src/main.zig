const std = @import("std");

const MAX_WORD_LENGTH :u8 = 20;

pub fn main() !void {
	const stdout = std.io.getStdOut().writer();
	try stdout.print("Welcome to hangman!\nPlease enter a word of max length {d}\n",.{MAX_WORD_LENGTH});

	var input: [MAX_WORD_LENGTH + 1]u8 = undefined;
	const stdin = std.io.getStdIn().reader();
	_ = try stdin.readUntilDelimiter(&input, '\n');

	try stdout.print("Selected word is {s}\n", .{input});
}