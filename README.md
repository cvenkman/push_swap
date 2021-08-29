# push_swap_bits

make
cd push_swap_visualizer
cp ../push_swap push_swap
python3.7 pyviz.py `ruby -e "puts (-200..200).to_a.shuffle.join(' ')"`