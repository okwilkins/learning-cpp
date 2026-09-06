# Pytorch Refresher

## Getting Started

### Enter the Dev Shell

All tools (Python 3.14, uv, ruff, ty) come from Nix.

```bash
nix develop --command $SHELL
```

### Sync the Project

```bash
uv sync
```

This creates `.venv` and installs the project (editable).

### Common commands

- Lint: `ruff check .`
- Format: `ruff format .`
- Type check: `ty check .`

Use `uv run` to execute anything inside the managed environment:

```bash
uv run python path/to/script.py
```

