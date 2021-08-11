"Vim's configuration file
"RAW's url: https://git.io/fjppd
"RAW's url2: gustavomejia.tech/.vimrc
"download1: curl -sLo ~/.vimrc https://git.io/fjppd
"reload file :so ~/.vimrc or :so %
"To find more info user :help <option> ex :help [ nocompatible ]
"To exit help use <C-w> q


function! Main()
    try
        call LoadPlugins()
    catch
        call VimPlugInstall()
    endtry
    call Settings()
    call Mappings()
    call SettingFiletypes()
    call SettingPlugins()
endfunction


function! LoadPlugins()
    """use :sort /\//

    call plug#begin('~/.vim/plugged')
    Plug 'rafi/awesome-vim-colorschemes'|           "awesome themes
    Plug 'mattn/emmet-vim'|                         "sippet autocomplete for html/css
    "Plug 'Yggdroot/indentLine'|                     "Create visual space indentation (python, bash, ruby)
    "Plug 'neomake/neomake'|                         "neomake for shellchecker
    Plug 'matze/vim-move'|                          "move blocks up and down
    Plug 'preservim/nerdcommenter'|                 "Create comments in file with <leader>cc
    Plug 'preservim/nerdtree'|                      "File Explorer NERDTree
    Plug 'luochen1990/rainbow'|                     "color brackets
    "Plug 'preservim/tagbar'                        "Tagbar menu
    Plug 'vim-airline/vim-airline'|                 "Awesome Status bar
    Plug 'vim-airline/vim-airline-themes'|          "Themes for status bar check https://github.com/vim-airline/vim-airline/wiki/Screenshots
    Plug 'moll/vim-bbye'|                           "requisit for vim-symlink and vimdiff
    Plug 'jeetsukumaran/vim-buffergator'|           "Set BufferTree
    Plug 'ryanoasis/vim-devicons'|                  "Custom Icons; Install Font Patchs before use https://github.com/ryanoasis/nerd-fonts
    Plug 'tpope/vim-fugitive'|                      "git integration
    Plug 'pangloss/vim-javascript'|                 "improve highlighting for javascript
    Plug 'roxma/vim-paste-easy'|                    "Enable paste-mode if you paste from clipboard (it checks speed)
    Plug 'tpope/vim-surround'|                      "surround
    Plug 'aymericbeaumet/vim-symlink'|              "open source of symbolic links
    "Plug 'christoomey/vim-tmux-navigator'|          "set tmux-navigation with vim check the repo for the tmux configuration
    if v:version >= 800
        Plug 'dense-analysis/ale'|                  "linting program
        Plug 'chrisbra/changesplugin'|              "show changes in git
        Plug 'rust-lang/rust.vim'
        if executable("ctags")
            Plug 'ludovicchabant/vim-gutentags'
        endif
        "Plug 'mg979/vim-visual-multi'               "Multi cursor
    else
        Plug 'vim-syntastic/syntastic'|             "Ale alternative for vim 700
        Plug 'szw/vim-tags'|                            "create tags :TagsGenerate[!] it needs exuberant-tags package
        if executable("autopep8")
            "Plug 'tell-k/vim-autopep8'|             "Edit files acording to pep8
        endif
    endif
    "Plug 'Athesto/vim-betty'|
    call plug#end()
endfunction

function! Settings()
    syntax on                                         "Coloring syntax and highlighting
    filetype indent on                                "enable filetype check for indent
    filetype plugin on                                "enable filetype check for plugin
    "set colorcolumn=80                                "a file should not have more than 80chars
    set cursorline                                    "highlight the line at the cursor
    set encoding=utf-8                                "encoding file for unicodes and accents
    set exrc                                          "run local .vimrc if it's present
    set hlsearch                                      "highlight search
    set incsearch                                     "increase search and highlight
    set laststatus=2                                  "show file name and save status
    set mouse=a
    set nocompatible                                  "disable compatibility with vi
    set noerrorbells                                  "no sounds
    set nowrap                                        "no wrap line if screen is not enough
    set number                                        "show line number
    set pastetoggle=<F2>                              "disable auto-identing in <C-S-v> with F2
    set path=.,**|                                    "include actual and all child into path. use :find <sub-file>
    "set relativenumber                                "show relative number
    set showcmd                                       "display cmds at bottom right of the screen
    "set splitbelow                                    "split buffers below and not above
    set splitright                                    "split buffers at right
    "set startofline                                  "????
    set t_Co=256                                      "patch, set explicit 256 colors for term w/o 256-color
    set t_u7=""                                       "patch, resolve starting with REPLACE mode on (Windows problem) https://github.com/vim/vim/issues/6365#issuecomment-652299438
    set t_ut=""                                       "patch, resolve whitespace color problem https://github.com/microsoft/terminal/issues/832
    set undodir=~/.vim/undodir                        "Undo directory for undo buffer
    set backupdir=~/.vim/backupdir                    "backupdir
    set backup
    set undofile                                      "save undo buffer in (undodir)ectory
    set wildmenu                                      "expland menu in the statusbar ex: :colorscheme <tab>
    set tabstop=4                                     "number of space with tab key
    set shiftwidth=4                                  "number of space with autoindenting
    highlight clear                                   "Clean highlight must go before colorscheme
    try
        colorscheme challenger_deep                   "Explicit colorscheme
    catch
        colorscheme ron
    endtry
    call CustomList()
    if v:version >= 800
        call Vim8Setup()
    endif
endfunction

function! CustomList()
    set list                                            "show special chars
    set listchars=|                                     "resetListchars
    set listchars+=tab:├┄                               "i_<C-v> u251c u2504
    set listchars+=tab:›·                               "i_<C-v> u203a u02fd
    set listchars+=tab:│\                               "i_<C-v> u2502 <space>
    set listchars+=tab:│·                               "i_<C-v> u2502 u02fd
    set listchars+=trail:˽                              "i_<C-v> u02fd
    set listchars+=trail:·                              "i_<C-v> u02fd
    let g:mySKfg=235
    execute "hi SpecialKey ctermfg =".g:mySKfg
endfunction

function! Mappings()
    """ to sort use sort /map /

    " mapping [ insert-mode ]
    let g:mapleader=" "
    inoremap jk <ESC>|                                  " i_jk            -> insert MODE mapping jk as ESC
    inoremap <C-c> <ESC>|                               " i_C-c           -> insert MODE mapping Ctrl-c as ESC, VisualBlock problem

    " mapping [ normal-mode ]\
    nnoremap * *N|                                      " n_*             -> don't change position with *\
    nnoremap <C-@> <C-^>|                               " n_C-K           -> change windows (up)
    nnoremap <C-H> <C-W><C-H>|                          " n_C-H           -> change windows (left)\
    nnoremap <C-J> <C-W><C-J>|                          " n_C-J           -> change windows (down)\
    nnoremap <C-K> <C-W><C-K>|                          " n_C-K           -> change windows (up)\
    nnoremap <C-L> <C-W><C-L>|                          " n_C-L           -> change windows (right)
    nnoremap <F3> :set wrap!<CR>:set wrap?<CR>|         " n_<F3>          -> toggle wrap
    nnoremap <F4> :set nu! list!<CR>|                   " n_<F4>          -> toggle numbers
    nnoremap <leader><esc> :nohl<CR>|                   " n_<leader><esc> -> clean format
    nnoremap <leader>U magUiw`a|                        " n_<leader>U     -> uppecase word
    nnoremap <leader>W :call WriteForced()<CR>|         " n_<leader>W     -> sudo save
    nnoremap <leader>b :BuffergatorToggle<CR>|          " n_<leader>b     -> Toggle BufferTree
    nnoremap <leader>e :NERDTreeToggle<CR>|             " n_<leader>e     -> toggle FileExplorer (NERDTree)
    nnoremap <leader>f :call Foobar()<CR>|              " n_<leader>f     -> test Foobar
    nnoremap <leader>i magg=G'a|                        " n_<leader>i     -> indent file
    nnoremap <leader>q :q<CR>|                          " n_<leader>q     -> quit
    nnoremap <leader>r :e<CR>|                          " n_<leader>r     -> reload file
    nnoremap <leader>u maguiw`a|                        " n_<leader>u     -> lowercase word
    nnoremap <leader>w :w<CR>|                          " n_<leader>w     -> save
    nnoremap <leader>xe :call EditVIMRC()<CR>|          " n_<leader>xe    -> edit VIMRC
    nnoremap G Gzz|                                     " n_G             -> center windows after search end
    "nnoremap R <Esc>|                                   " n_R            -> patch, Disable ReplaceMode (Fix Windows OS Problems)
    nnoremap [b :bp<CR>|                                " n_C-K           -> change windows (up)
    nnoremap ]b :bn<CR>|                                " n_C-K           -> change windows (up)
    "nnoremap g<F1> :help <C-R><C-F><CR>|                " n_g<F1>        -> use insted K on the word open help for word under the cursor Ex. use g<F1> -> cmdline
    "nnoremap q: <nop>|                                  " n_q:           -> disable history windows (it gives me conficts)
    nnoremap [t :tabprevious<CR>|                       " n_C-K           -> change windows (up)
    nnoremap ]t :tabnext<CR>|                           " n_C-K           -> change windows (up)
    nnoremap [e :ALEPrevious<CR>|                       " n_C-K           -> change windows (up)
    nnoremap ]e :ALENext<CR>|                           " n_C-K           -> change windows (up)

    " mapping  [ cmdline-mode ]
    cnoremap <C-A> <Home>|                              " c_Ctrl-A    -> go to Beginning of line
    cnoremap <C-B> <Left>|                              " c_Ctrl-b    -> backward a char
    cnoremap <C-F> <Right>|                             " c_Ctrl-f    -> fordward a char
    cnoremap <C-d> <Right><BS>|                         " c_Ctrl-d    -> delete char forward
    cnoremap <ESC><BS> <C-W>|                           " c_Meta-DEL  -> delete word backward
    cnoremap <ESC>b <S-Left>|                           " c_Meta-b    -> backward a word
    cnoremap <ESC>d <S-Right><Right><C-W>|              " c_Meta-d    -> delete word forward
    cnoremap <ESC>f <S-Right>|                          " c_Meta-f    -> fordward a word

    " mapping [ visual-mode ]
    vnoremap <leader>y :call YankToXclip()<CR>|         " v_<leader>y -> yank selection to clipboard with xclip
endfunction

function! SettingFiletypes()
    augroup Filetypes
        autocmd!
        autocmd BufReadPost *.asm       set filetype=nasm
        autocmd BufReadPost *.cfg       set filetype=conf
        autocmd BufReadPost *.h         set filetype=c
        autocmd BufReadPost *.pp        set filetype=puppet
        autocmd BufReadPost man_[1-9]_* set filetype=nroff
        autocmd Filetype sh             set expandtab sw=4 ts=4 sts=4
        autocmd Filetype c              set noexpandtab sw=4 ts=4 sts=4 "explicit, I had problem with nasm and c
        autocmd Filetype nasm           set expandtab sw=8 ts=8 sts=8
        autocmd Filetype conf           set expandtab
        autocmd Filetype html           set expandtab sw=2 ts=2 sts=2
        autocmd Filetype javascript     set expandtab sw=2 ts=2 sts=2
        autocmd Filetype puppet         set expandtab
        autocmd Filetype ruby           set expandtab sw=4 ts=4 sts=4
        autocmd Filetype vim            set expandtab sw=4 ts=4 sts=4

        let g:html_indent_inctags = ""                      "autointent new line after enter
        let g:html_indent_autotags = "p,html"               "no autoindent with format

        augroup highlight_over80
            autocmd!
            autocmd Filetype * highlight OverLength ctermbg=167 ctermfg=234 guibg=#592929
            autocmd Filetype * match OverLength //|                                 "patch, 1. edit py, 2. edit another file
            autocmd Filetype c,markdown,python match OverLength /\%80v.\+/
        augroup END

        augroup auto_format_nasm
            autocmd BufWritePost *.asm call Nasmfmt()
        augroup END

        augroup Remove_trailing_whitespaces
            autocmd BufWritePre *.c,*.h  %s/\s\+$//e
        augroup END

        augroup mysql
            autocmd!
            autocmd BufWritePre *.sql
                        \ :%s/
                        \\(select\|\order\|by\|from\|where\|show\|grant\)/
                        \\U\1/ge
        augroup END
    augroup END
endfunction

function! SettingPlugins()
    augroup Plugins_Filetypes
        autocmd!
        autocmd FileType html,css EmmetInstall                                   "only use in css and html
        autocmd FileType nerdtree RainbowToggleOff                               "Disable Rainbow brackets in NERDTree
        autocmd Filetype c,sh let g:NERDSpaceDelims = 2                             "NerdCommenter spaces 1
        autocmd Filetype fugitive
                    \ nnoremap <buffer> <leader>?
                    \ :below vertical help fugitive-maps<cr> |                   "remap g? right split the help messages
    augroup END

    if !exists('g:airline_symbols')
        let g:airline_symbols = {"dirty":"*", "crypt":"Cr"}                      "Fix airline-icons (2) spaces [ airline-customization ]
    endif
    let g:airline_left_sep = "\ue0bc"                                            "left icon as diagonal -> https://github.com/ryanoasis/powerline-extra-symbols#glyphs
    let g:airline_powerline_fonts = 1                                            "use the nerd-font
    let g:airline_right_sep = "\ue0be"                                           "right icon as diagonal
    let g:airline_theme = 'minimalist'                                           "airline themes -> https://github.com/vim-airline/vim-airline/wiki/Screenshots

    let g:ale_fixers = {
                \'rust': ['rustfmt'],
                \'python' : ['autopep8'],
                \'javascript': ['standard']}
    let g:ale_linters = {
                \'rust': ['rustc', 'rls', 'cargo'],
                \'python' : ['pycodestyle'],
                \'javascript': ['standard']}
    let g:ale_c_cc_options = '-std=gnu90 -Wall -Wextra -Werror -pedantic'        "c options
    let g:ale_nasm_nasm_options = '-f elf64'
    let g:ale_completion_enabled = 1
    let g:ale_fix_on_save = 1                                                    "fixautopep after save file
    let g:ale_javascript_standard_executable = 'semistandard'                    "set semistandard executable as standard
    let g:ale_javascript_standard_options = '--global $'                         "disable jquery warning
    let g:ale_javascript_standard_use_global = 1
    let g:ale_python_pycodestyle_executable = 'pep8'
    let g:ale_python_pycodestyle_use_global = 1
    set omnifunc=ale#completion#OmniFunc

    let g:NERDCustomDelimiters = { 'nroff': { 'left': '.\\"'} }
    let g:autopep8_disable_show_diff=1                                           "disable diff
    let g:autopep8_on_save = 1                                                   "Run autopep8 everytime that save
    let g:buffergator_suppress_keymaps = 1                                       "Let me set <leader>b as BuffergatorToggle
    let g:changes_vcs_check = 1                                                  "enable git check
    let g:gutentags_ctags_tagfile = ".git/tags"                                  "set tags into the .git directory
    let g:indentLine_char = '│'                                                  "using for indentation i_<C-v> u203a u02fd
    let g:indentLine_color_term = g:mySKfg                                         "set color as the colorscheme
    let g:neomake_shellcheck_args = ['-fgcc']                                    "fix ERROR with neomake and shellcheck
    let g:rainbow_active = 1                                                     "set to 0 if you want to enable it later via :RainbowToggle
    let g:user_emmet_install_global = 0                                          "disable emmet
    let g:user_emmet_leader_key = '<Tab>'                                        "autocomplete with tab

    augroup vimMove
        autocmd!
        let g:move_map_keys = 0
        nmap <esc>j <Plug>MoveLineDown
        nmap <esc>k <Plug>MoveLineUp
        vmap <esc>j <Plug>MoveBlockDown
        vmap <esc>k <Plug>MoveBlockUp
    augroup end

    let g:syntastic_c_compiler_options =
                \'-std=gnu90 -Wall -Wextra -Werror -pedantic'

    let g:NERDTreeNaturalSort = 1                                                "NerdTree sort 1, 2, 3, 100, 1000
    augroup myBufenter
        autocmd!
        "autocmd bufwinenter * silent NERDTreeMirror                                  "Open the existing NERDTree on each new tab.
        autocmd bufenter * if (winnr("$") == 1 &&
                    \exists("b:NERDTree") &&
                    \b:NERDTree.isTabTree()) | q | endif                         "close all if there is only one window
    augroup END

endfunction

function! Vim8Setup()
    " mapping [ normal-mode ]
    nnoremap <C-W>% <C-W>:below vertical terminal<CR>
    nnoremap <C-W>" <C-W>:below terminal<CR>

    " mapping [ terminal-mode ]
    tnoremap <C-W>% <C-W>:below vertical terminal<CR>
    tnoremap <C-W>" <C-W>:below terminal<CR>
    packadd termdebug                              "use Terminal Plugin

    "call VimIDE()
    let g:termdebug_popup = 0
    let g:termdebug_wide = 163                     "split windows Vertically
endfunction


""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"--------------------------------------------------------MY FUNCTIONS--------------------------------------------------------"
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
function! VimIDE()
    tnoremap <C-H> <C-W><C-H>|                        " n_C-H       -> change windows (left)
    tnoremap <C-J> <C-W><C-J>|                        " n_C-J       -> change windows (down)
    tnoremap <C-K> <C-W><C-K>|                        " n_C-K       -> change windows (up)
    "tnoremap <C-L> <C-W><C-L>|                        " n_C-L       -> change windows (right)

    set termwinsize=12x0
    autocmd VimEnter * NERDTree
    autocmd VimEnter * wincmd p
    below terminal
endfunction

function! WriteForced()
    execute ':silent w !sudo tee % > /dev/null'
    edit!
endfunction

function! EditVIMRC()
    execute ':silent tabedit $MYVIMRC'
    echom ".vimrc"
endfunction

function! YankToXclip()
    execute ':normal! gv"yy'
    call system('xclip -selection clipboard', @y)
endfunction

function! ClearRegisters()
    let regs=split('abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789/-"', '\zs')
    for r in regs
      call setreg(r, [])
    endfor
endfunction

function! Nasmfmt()
    """ Format the nasm file with the binary nasmfmt, repo -> https://github.com/yamnikov-oleg/nasmfmt
    if executable('nasmfmt')
        execute ':silent !nasmfmt -ci 35 %'
        edit!   "don't need L<CR> for reload
        redraw! "it's necesary you call the function manually
    endif
endfunction

function! Foobar()
    echom 'testing function'
endfunction

function! VimPlugInstall()

    silent !mkdir -p $HOME/.vim/undodir
    silent !mkdir -p $HOME/.vim/backupdir
    if !executable('git')
        echohl WarningMsg | echomsg "Warning: Vim-plug needs git to install the plugins" | echohl None
        return
    endif

    if !executable('curl')
        echohl WarningMsg | echomsg "Warning: Vim-plug needs curl for the installation" | echohl None
        return
    endif

    if !exists("*plug#begin")
        silent !echo -e "\033[0m\033[31m\nOh no\!, Vim-plug manager is not found, Don't worry, I will install it\033[0m"
        !curl -fLo ~/.vim/autoload/plug.vim --create-dirs https://raw.githubusercontent.com/junegunn/vim-plug/master/plug.vim
        call Main()
        PlugInstall
        quit
    endif

endfunction

""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""
"--------------------------------------------------------ENTRY POINT---------------------------------------------------------"
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

call Main()
set noswapfile
let g:gutentags_enabled = 0
