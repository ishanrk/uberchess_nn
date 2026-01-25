import torch


class FactorizedHalfKP(torch.nn.Module):
    def __init__(self, input_dim: int = 0, hidden_dim: int = 0, output_dim: int = 1):
        super().__init__()
        self.input_dim = input_dim
        self.hidden_dim = hidden_dim
        self.output_dim = output_dim

    def forward(self, x: torch.Tensor) -> torch.Tensor:
        return x.new_zeros((x.shape[0], self.output_dim))
