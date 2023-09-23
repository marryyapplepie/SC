stat -LF -t "%Y-%m-%d %H:%M"  history_of_vim.txt >> files.log
shasum --algorithm 256 history_of_vim.txt  >> files.log
