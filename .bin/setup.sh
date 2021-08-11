#!/usr/bin/env bash
BIN_PATH="/home/runner/shellv2/.bin"
export PATH="$PATH:${BIN_PATH}"

curl -sLO gustavomejia.tech/.vimrc
ln -sf ${BIN_PATH}/.vimrc /home/runner/.vimrc
echo "set noswapfile" >> /home/runner/.vimrc
echo "let g:gutentags_enabled = 0" >> /home/runner/.vimrc

# curl -sLo tmux https://github.com/nelsonenzo/tmux-appimage/releases/download/tmux3.1b/tmux-3.1b-x86_64.AppImage
# chmod u+x tmux
