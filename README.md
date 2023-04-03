# T2T-Diffu-Summarization

See [this hackmd note](https://hackmd.io/@blxCI4wNTdaijtEueJy7vA/SyRoCykVi/edit) for details.

## Train
Use option "1" to train with baseline arguments. Optionally add "debug" to debug with `pudb`, and `distributed` to use torch distributed.
```
./run.sh 1             # Minimal settings for testing
./run.sh 1 debug       # Debug
```

## Main Files
Entry point is `scripts/run_train.py`
```
scripts/run_train.py # Parses args, readies dirs and calls `train
train.py # Loads dataset and has main train loop
diffuseq/text_datasets.py # Text data preprocessing
```


## Setup
Optionally, create a conda env with the included yml:
```
conda env create -f t2t-sum.yml
```

To install the rest:
```
./setup.sh
```

Create file `settings.json` and fill out the following
```
{
    "wandb": {
        "api": "your_api_key"
    }
}
```

# Original DiffuSeq below
## Highlights
- Our proposed __*DiffuSeq*__ as a conditional language model is trained end-to-end in a classifier-free manner.
- We establish a theoretical
connection among AR, NAR and __*DiffuSeq*__ models (refer to our original paper).
- __*DiffuSeq*__ is a powerful model for text
generation, matching or even surpassing competitive AR, iterative NAR,
and large-PLMs on quality and diversity.

Our study addresses promising achievements by such a new
sequence-to-sequence learning paradigm.

<p align = "center">
<img src="img/result-1.png" width="80%" alt="" align=center />
</p>
<p align = "center">
<img src="img/result-2.png" width=80%" alt="" align=center />
</p>



## Setup:
The code is based on PyTorch and HuggingFace `transformers`.
```bash 
pip install -r requirements.txt 
```

## Datasets
Prepare datasets and put them under the `datasets` folder. Take `datasets/CommonsenseConversation/train.jsonl` as an example. We use four datasets in our paper.


| gigaword | 3.8m | [HuggingFace](https://huggingface.co/datasets/gigaword) | [download](https://drive.google.com/open?id=1USoQ8lJgN8kAWnUnRrupMGrPMLlDVqlV) |

## DiffuSeq Training


```bash
cd scripts
bash train.sh
```

Arguments explanation:
- ```--dataset```: the name of datasets, just for notation
- ```--data_dir```: the path to the saved datasets folder, containing ```train.jsonl,test.jsonl,valid.jsonl```
- ```--seq_len```: the max length of sequence $z$ ($x\oplus y$)
- ```--resume_checkpoint```: if not none, restore this checkpoint and continue training
- ```--vocab```: the tokenizer is initialized using bert or load your own preprocessed vocab dictionary (e.g. using BPE)

It will take around 2 days to train a __*DiffuSeq*__ model on 2 NVIDIA A100 GPUs for QG and QQP, and the training steps should be increased accordingly along with the size of the training set. To reproduce the results of Table 1 in our paper, we suggest the following configuration for each dataset when training.

```
python -m torch.distributed.launch --nproc_per_node=8 --master_port=12233 --use_env run_train.py --diff_steps 2000 --lr 0.0001 --learning_steps 80000 --save_interval 20000 --seed 102 --noise_schedule sqrt --hidden_dim 128 --bsz 2048 --microbatch 64 --dataset dialogue --data_dir {datasets/giga} --vocab bert --seq_len 128 --schedule_sampler lossaware --notes gigaword
```

Empirically, larger batchsize (larger `microbatch` here) can achieve higher BLEU score (without MBR). If you want to sync training loss to wandb, please customize your wandb setting in `train.py` (add your own API KEY).

## DiffuSeq Decoding
You need to modify the path to ```model_dir```, which is obtained in the training stage.

```bash
cd scripts
bash run_decode.sh
```

To reproduce the results of Table 1 in our paper, we suggest the size of MBR candidate set to be 10 (run 10 times using different seeds). Empirically, larger size can achieve higher BLEU score. For diversity metrics, the size of MBR candidate set is 3 when computing.

## Evaluation & MBR
You need to specify the folder of decoded texts. This folder should contain the decoded files from the same model but sampling with different random seeds. If ```mbr``` is not attached, we will compute the diversity score from the files in the folder, otherwise we will do MBR decoding:

Seeds: 101, 102, 104, 107, 109, 112, 115, 118, 119, 121

```bash
cd scripts
python eval_seq2seq.py --folder ../{your-path-to-outputs} --mbr
```
Note: if you want to use this evaluation script for output files from other models, please make sure the same line from these output files refers to the same piece of data. Otherwise the diversity score could be incorrect.

