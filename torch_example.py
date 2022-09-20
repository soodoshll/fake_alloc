import torch
from torch import nn

import fake_alloc

device = 'cuda'

# create a 500-layer MLP, each one has a weight matrix with size of 4*4096*4096=64MB
# in total ~30G
model = nn.Sequential(
    *[nn.Linear(4096, 4096, bias=False, device=device) for _ in range(500)]
)

x = torch.rand((4096, 4096), device=device) # also intermediate activation 500*4096*4096 ~ 30G

o = model(x).sum()
o.backward()

print(f"peak mem allocated: {fake_alloc.max_mem_allocated()/1e9 : .1f} GB")