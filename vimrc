:colorscheme jellybeans
set belloff=all

:vnoremap <A-Right> lholhxp`[1v
:vnoremap <A-Left> hlohlxhP`[1v
set shiftwidth=2
set tabstop=2

noremap <F8> <ESC> :w <CR> :!g++ -std=c++17 -O2 -o %< % && ./%< < inp<CR>
inoremap <F8> <ESC> :w <CR> :!g++ -std=c++17 -O2 -o "%<" "%" && "./%<" < inp<CR>


function! s:swap_lines(n1, n2)
    let line1 = getline(a:n1)
    let line2 = getline(a:n2)
    call setline(a:n1, line2)
    call setline(a:n2, line1)
endfunction

function! s:swap_up()
    let n = line('.')
    if n == 1
        return
    endif

    call s:swap_lines(n, n - 1)
    exec n - 1
endfunction

function! s:swap_down()
    let n = line('.')
    if n == line('$')
        return
    endif

    call s:swap_lines(n, n + 1)
    exec n + 1
endfunction

noremap <silent> <c-s-up> :call <SID>swap_up()<CR>
noremap <silent> <c-s-down> :call <SID>swap_down()<CR>


