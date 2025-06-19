
default:
    just --list

enter_shell:
    cd ~/qmk_firmware/ && nix-shell --run "cd ~/projekte/qmk_userspace && zsh"

build_3w6hs:
     qmk compile -kb beekeeb/3w6hs -km fabianpage && sudo mount -t drvfs D: /mnt/d && cp beekeeb_3w6hs_fabianpage.uf2 /mnt/d/
